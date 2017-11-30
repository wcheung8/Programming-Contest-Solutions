
x = input()

if x[-1] == '?':
    print('7')
elif " Susuu " in x or " Susuu!" in x or " Susuu?" in x or "Susuu " in x[0:len("Susuu")] or "Susuu!" in x or "Susuu?" in x:
    print("AI SUSSU!")
else:
    print("O cara é bom!")