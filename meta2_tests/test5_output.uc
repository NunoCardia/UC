Program
..FuncDefinition
....Int
....Id(main)
....ParamList
......ParamDeclaration
........Void
....FuncBody
......Store
........Id(a)
........Add
..........Id(a)
..........Id(b)
......Store
........Id(b)
........Add
..........IntLit(1)
..........IntLit(3)
......Store
........Id(c)
........Add
..........Add
............Add
..............Id(a)
..............Id(b)
............Id(c)
..........Id(d)
......Store
........Id(d)
........Add
..........Add
............IntLit(1)
............Id(a)
..........Id(c)
......Store
........Id(e)
........Mul
..........Id(a)
..........IntLit(2)
......Store
........Id(f)
........Mul
..........Mul
............Id(a)
............Id(b)
..........Id(c)
......Store
........Id(g)
........Div
..........Mul
............Id(a)
............Id(b)
..........IntLit(2)
......Store
........Id(h)
........Sub
..........Sub
............Id(a)
............Id(a)
..........Mul
............Id(b)
............Id(c)
......Store
........Id(i)
........Add
..........Mod
............Id(p)
............IntLit(20)
..........Mod
............Id(c)
............IntLit(30)
......Store
........Id(j)
........Add
..........Sub
............Mul
..............IntLit(1)
..............Id(h)
............IntLit(6)
..........Id(p)
......Store
........Id(l)
........Sub
..........Id(p)
..........Id(o)
......Store
........Id(m)
........Add
..........Add
............Id(a)
............Id(b)
..........Sub
............Id(z)
............Id(p)
......Store
........Id(n)
........Id(a)
......Store
........Id(p)
........Call
..........Id(bla)
..........Id(b)
..........Id(c)
..........Id(z)
......Store
........Id(q)
........Lt
..........Id(b)
..........Sub
............Add
..............Sub
................Mul
..................Mod
....................Id(c)
....................IntLit(20)
..................Id(c)
................Id(a)
..............Id(q)
............Call
..............Id(aass)
..............Eq
................Id(b)
................Add
..................Id(c)
..................Id(p)
......Comma
........Comma
..........Id(a)
..........Id(b)
........Store
..........Id(c)
..........IntLit(0)
