// Arup Guha
// Solution to 2014 World Finals Problem: Sensor Network
// Completed on 7/4/2014
// Also got the idea of how to solve this from Derek Kisman.

import java.util.*;

public class i {

	public static int n;
	public static int sqd;
	public static pt[] list;
	public static int max;
	public static int[][] adj;
	public static TreeSet<Integer> bestPts;
	public static HashMap<Integer,Integer> flowMap;

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		n = stdin.nextInt();
		int d = stdin.nextInt();

		// Store s
		sqd = d*d;

		// Read in points.
		list = new pt[n];
		for (int i=0; i<n; i++) {
			int x = stdin.nextInt();
			int y = stdin.nextInt();
			list[i] = new pt(x, y);
		}

		// Pre-compute distances.
		adj = new int[n][n];
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				adj[i][j] = list[i].distsq(list[j]);

		// Try each pair of pts as being the farthest away in the set.
		max = 1;
		bestPts = new TreeSet<Integer>();
		bestPts.add(0);
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				TreeSet<Integer> curList = solve(i,j);
				if (curList.size() > max) {
					max = curList.size();
					bestPts = curList;
				}
			}
		}

		// Print results.
		System.out.println(max);
		for (Integer x: bestPts)
			System.out.print((x+1)+" ");
		System.out.println();
	}

	public static TreeSet<Integer> solve(int v1, int v2) {

		// A dummy answer for cases that can't be maximum.
		TreeSet<Integer> ans = new TreeSet<Integer>();
		ans.add(v1);

		// Can't build set from these two points.
		if (adj[v1][v2] > sqd) return ans;

		int maxDsq = adj[v1][v2];

		// Initially mark each vertex as invalid.
		int[] color = new int[n];
		Arrays.fill(color, -1);

		// Mark all vertices within closer to v1&v2 than the distance between v1 and v2.
		TreeSet<Integer> set = new TreeSet<Integer>();
		for (int i=0; i<n; i++) {
			if (i == v1 || i == v2) continue;
			if (adj[v1][i] <= maxDsq && adj[v2][i] <= maxDsq) {
				color[i] = 0;
				set.add(i);
			}
		}

		// Don't do the work here!
		if (set.size()+2 <= max) return ans;

		// Color each component.
		for (Integer x: set)
			if (color[x] == 0)
				twoColor(set, x, 1, color);

		// Get the best solution and return.
		ans = getBest(color, set);
		ans.add(v1);
		ans.add(v2);
		return ans;
	}

	// Puts an edge between vertices in subgraph that are too far apart.
	public static Edge[][] formGraph(int[] color) {

		flowMap = new HashMap<Integer,Integer>();
		Edge[][] myAdj = new Edge[n+2][];

		// Put in connections between vertices too far away.
		int color1 = 0;
		for (int i=0; i<n; i++) {

			LinkedList<Integer> next = new LinkedList<Integer>();
			for (int j=0; j<n; j++)
				if (color[i] == 1 && color[j] == 2 && adj[i][j] > sqd)
					next.offer(j);

			myAdj[i] = new Edge[next.size()];
			int cnt = 0;
			while (next.size() > 0)
				myAdj[i][cnt++] = new Edge(1, next.poll());

			if (color[i] == 1) color1++;
		}

		// Put in edges from source and to sink.
		myAdj[n] = new Edge[color1];
		myAdj[n+1] = new Edge[0];
		int c1 = 0;
		for (int i=0; i<n; i++) {
			if (color[i] == 1) {
				flowMap.put(i,c1);
				myAdj[n][c1++] = new Edge(1,i);
			}
			if (color[i] == 2) {
				myAdj[i] = new Edge[1];
				myAdj[i][0] = new Edge(1,n+1);
			}
		}
		return myAdj;
	}


	// Two colors this connected component with colors 1 and 2.
	public static void twoColor(TreeSet<Integer> set, int v, int shade, int[] color) {

		// Color this node.
		color[v] = shade;
		int nextShade = 3-shade;

		// Lazy man's two coloring for a small graph that is definitely two colorable.
		for (Integer x: set)
			if (color[x] == 0 && adj[v][x] > sqd)
				twoColor(set, x, nextShade, color);
	}

	public static TreeSet<Integer> getBest(int[] color, TreeSet<Integer> set) {

		// Get the initial flow graph.
		Edge[][] graph = formGraph(color);
		netflow myFlow = new netflow(graph, n, n+1);
		int matching = myFlow.getMaxFlow();
		return myFlow.getMaxIS();
	}

}

class pt {

	public int x;
	public int y;

	public pt(int myX, int myY) {
		x = myX;
		y = myY;
	}

	public int distsq(pt other) {
		return (x-other.x)*(x-other.x) + (y-other.y)*(y-other.y);
	}
}


/*** My awful network flow code follows ***/

class Edge {

	public int dest;
	public int capacity;
	public int flow;

	public Edge(int cap, int d) {
		capacity = cap;
		flow = 0;
		dest = d;
	}

	public int maxPushForward() {
		return capacity - flow;
	}

	public int maxPushBackward() {
		return flow;
	}

	public boolean pushForward(int moreflow) {

		// We can't push through this much flow.
		if (flow+moreflow > capacity)
			return false;

		// Push through.
		flow += moreflow;
		return true;
	}

	public boolean pushBack(int lessflow) {

		// Not enough to push back on.
		if (flow < lessflow)
			return false;

		flow -= lessflow;
		return true;
	}
}

class direction {

	public int prev;
	public boolean forward;

	public direction(int node, boolean dir) {
		prev = node;
		forward = dir;
	}

	public String toString() {
		if (forward)
			return "" + prev + "->";
		else
			return "" + prev + "<-";
	}
}

class netflow {

	private Edge[][] adjMat;
	private int source;
	private int dest;
	private HashMap[] lookup;
	private LinkedList[] backEdgeLookup;
	private int flow;

	// Input matrix is edge list.
	public netflow(Edge[][] matrix, int start, int end) {

		// Set up easy stuff.
		adjMat = matrix;
		source = start;
		dest = end;
		lookup = new HashMap[matrix.length];

		// Allocate empty LLs.
		backEdgeLookup = new LinkedList[matrix.length];
		for (int i=0; i<matrix.length; i++)
			backEdgeLookup[i] = new LinkedList<Integer>();

		// Fill these in.
		for (int i=0; i<adjMat.length; i++) {

			lookup[i] = new HashMap<Integer,Integer>();
			for (int j=0; adjMat[i] != null && j<adjMat[i].length; j++) {
				lookup[i].put(adjMat[i][j].dest, j);
				backEdgeLookup[adjMat[i][j].dest].offer(i);
			}
		}
	}

	public TreeSet<Integer> getMaxIS() {

		// Go through each possible matching.
		for (int i=0; i<adjMat[source].length; i++) {

			// This vertex participates in a matching.
			if (adjMat[source][i].flow > 0) {

				// Find its matching pair.
				int from = adjMat[source][i].dest;

				for (int j=0; j<adjMat[from].length; j++) {
					if (adjMat[from][j].flow > 0) {

						// Set flow of this path to 0.
						adjMat[source][i].flow = 0;
						adjMat[from][j].flow = 0;
						adjMat[adjMat[from][j].dest][0].flow = 0;

						// Remove one or the other depending on which lowers the flow.
						adjMat[source][i].capacity = 0;
						if (findAugmentingPath() == null) break;
						adjMat[source][i].capacity = 1;
						adjMat[adjMat[from][j].dest][0].capacity = 0;
					}
				}
			}
		}

		TreeSet<Integer> res = new TreeSet<Integer>();

		// Add all chosen from left side.
		for (int i=0; i<adjMat[source].length; i++)
			if (adjMat[source][i].capacity > 0)
				res.add(adjMat[source][i].dest);

		// Add all chosen from right side.
		for (int i=0; i<adjMat.length; i++) {

			if (i == source || i == dest) continue;
			if (adjMat[i].length == 1 && adjMat[i][0].capacity == 1 && adjMat[i][0].dest == dest)
				res.add(i);
		}

		return res;
	}

	public ArrayList<direction> findAugmentingPath() {

		// This will store the previous node visited in the BFS.
		direction[] prev = new direction[adjMat.length];
		boolean[] inQueue = new boolean[adjMat.length];
		for (int i=0; i<inQueue.length; i++)
			inQueue[i] = false;

		// The source has no previous node.
		prev[source] = new direction(-1, true);

		LinkedList<Integer> bfs_queue = new LinkedList<Integer>();
		bfs_queue.offer(new Integer(source));
		inQueue[source] = true;

		// Our BFS will go until we clear out the queue.
		while (bfs_queue.size() > 0) {

			// Add all the new neighbors of the current node.
			Integer next = bfs_queue.poll();

			if (adjMat[next] == null) continue;

			// Find all neighbors and add into the queue. These are forward edges.
			for (int i=0; i<adjMat[next].length; i++) {

				int item = adjMat[next][i].dest;
				if (!inQueue[item] && adjMat[next][i].maxPushForward() > 0) {
					bfs_queue.offer(item);
					inQueue[item] = true;
					prev[item] = new direction(next, true);
				}
			}

			// Now look for back edges.
			for (int i=0; i<backEdgeLookup[next].size(); i++) {

				int item = (Integer)backEdgeLookup[next].pollFirst();
				if (!inQueue[item] && lookup[item].containsKey(next) && adjMat[item][(Integer)(lookup[item].get(next))].maxPushBackward() > 0) {
					bfs_queue.offer(item);
					inQueue[item] = true;
					prev[item] = new direction(next, false);
				}
				backEdgeLookup[next].offer(item);
			}
		}

		// No augmenting path found.
		if (!inQueue[dest])
			return null;

		ArrayList<direction> path = new ArrayList<direction>();

		direction place = prev[dest];

		direction dummy = new direction(dest, true);
		path.add(dummy);

		// Build the path backwards.
		while (place.prev != -1) {
			path.add(place);
			place = prev[place.prev];
		}

		// Reverse it now.
		Collections.reverse(path);

		return path;
	}

	// Run the Max Flow Algorithm here.
	public int getMaxFlow() {

		flow = 0;

		ArrayList<direction> nextpath = findAugmentingPath();

		// Loop until there are no more augmenting paths.
		while (nextpath != null) {

			// Check what the best flow through this path is.
			int this_flow = Integer.MAX_VALUE;
			for (int i=0; i<nextpath.size()-1; i++) {

				if (nextpath.get(i).forward) {
					this_flow = Math.min(this_flow, adjMat[nextpath.get(i).prev][(Integer)lookup[nextpath.get(i).prev].get(nextpath.get(i+1).prev)].maxPushForward());
				}
				else {
					this_flow = Math.min(this_flow, adjMat[nextpath.get(i+1).prev][(Integer)lookup[nextpath.get(i+1).prev].get(nextpath.get(i).prev)].maxPushBackward());
				}
			}

			// Now, put this flow through.
			for (int i=0; i<nextpath.size()-1; i++) {

				if (nextpath.get(i).forward) {
					adjMat[nextpath.get(i).prev][(Integer)lookup[nextpath.get(i).prev].get(nextpath.get(i+1).prev)].pushForward(this_flow);
				}
				else {
					adjMat[nextpath.get(i+1).prev][(Integer)lookup[nextpath.get(i+1).prev].get(nextpath.get(i).prev)].pushBack(this_flow);
				}
			}

			// Add this flow in and then get the next path.
			flow += this_flow;
			nextpath = findAugmentingPath();
		}

		return flow;
	}
}

