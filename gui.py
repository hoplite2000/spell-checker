from tkinter import*
import subprocess
from subprocess import*

def end():
    screen.destroy()

def clear():
    inputT.delete("1.0",END)
    outputT.delete("1.0",END)

def check():
    a= inputT.get("1.0","end")
    m=len(a)
    a=a[:m-1]
    if " " in a or not a.isalpha():
        def exit_popup():
            er.destroy()
            inputT.delete("1.0",END)
        er= Toplevel(screen)
        x = screen.winfo_x()+150
        y = screen.winfo_y()+100
        w = 450
        h = 250
        er.geometry("%dx%d+%d+%d" % (w, h, x, y))
        er.title("FATAL ERROR")
        label1=Label(er,text="INVALID INPUT",font=("Calibri", 22, "bold"), fg="red").place(x=130,y=25)
        label2=Label(er,text="Enter a single word",font=("Calibri", 15, "bold")).place(x=140,y=70)
        label3=Label(er,text="Input word must contain alphabets only",font =("Calibri", 15, "bold")).place(x=50,y=110)
        but=Button(er,text="CONTINUE",bg="red",width="7",height="2",command=exit_popup).place(x=190,y=165)
        er.mainloop()
    else :
        subprocess.call(["g++","edit.cpp","soundex.cpp","spell_check.cpp"])
        value = a + '\n'
        value = bytes(value, 'UTF-8')  # Needed in Python 3.
        proc = Popen("./a.out", stdin=PIPE, stdout=PIPE)
        out, err = proc.communicate(input=value)
        out = str(out)
        out=out[2:len(out)-2]
        out=out.split(',')
        for i in out:
            outputT.insert(END,i+'\t')

screen = Tk()
screen.geometry("750x500")
screen.configure(bg="black")
screen.title("SPELL CHECKER")
inputL=Label(screen, text="Enter the word", width="15", height="2", font=("Calibri",15, "bold"), bg="black", fg="white")
inputL.place(x=55, y=60)
outputL=Label(screen,text="Output",width="15",height="2",font=("Calibri",15, "bold"), bg="black", fg="white")
outputL.place(x=25, y=120)
inputT=Text(screen, width=45, height="2")
inputT.place(x=215, y=62)
outputT=Text(screen, width=80, height="12")
outputT.place(x=55,y=165)
checkb=Button(text="CHECK", width="7", height="2", bg="white", command=check)
checkb.place(x=600,y=58)
clearb=Button(text="CLEAR", width="7", bg="white", height="2", command=clear)
clearb.place(x=325,y=405)
exitb=Button(text="EXIT", width="5",bg="red", height="1", command=end)
exitb.place(x=650,y=430)
screen.mainloop()




