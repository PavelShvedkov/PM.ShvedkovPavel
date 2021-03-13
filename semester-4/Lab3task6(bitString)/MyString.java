package com.company;


public class MyString {
    protected char[] array;
    protected int length;

    public MyString(){
        length=0;
        array=new char[0];
    }
    public MyString(char[] other){
        if (other.length==0){
            System.out.println("Source string empty");
            length=0;
            array=new char[0];
            return;
                    }

        array=new char[other.length];//posible lost data
        length=other.length;
        array=other.clone();
    }
    public  MyString(MyString other){
     if  (other.getLength()==0) {
         System.out.println("Source sting empty");
         length=0;
         array=new char[0];
     }

     length=other.getLength();
     array=other.array.clone();
    }

    public void displayMyString(){
        if(length==0){
            System.out.println("String is empty");
            return;
        }
        System.out.println(array);
    }
    public int getLength(){
    return array.length;
    }
    public char getItem(int index){
        if (index<0||index>length){
            System.out.println("Invalid index!");
            return 0;
        }

        return array[index];
    }
    public void clear(){
        if(length==0){
            return;
        }

        length=0;
        array=null;
    }
    public  MyString addToEnd(char item){
        MyString buffer=new MyString();

        if(this.getLength()<=0)
        {
           buffer.array[0]=item;
           buffer.length++;

           return buffer;
        }

        buffer=this;
        buffer.array[this.getLength()]=item;
        buffer.length++;
        return buffer;
    }
    public MyString addToBegin(char item){
        MyString buffer=new MyString();

        if(this.getLength()<=0)
        {
            buffer.array=new char[1];
            buffer.array[0]=item;
            buffer.length++;

            return buffer;
        }

buffer.array=new char[this.getLength()+1];
        for (int i=1;i<this.getLength()+1;++i){
            buffer.array[i]=this.getItem(i-1);
        }

        buffer.array[0]=item;

        buffer.length=this.getLength()+1;
        return buffer;
    }
    public boolean areEqual(MyString rho){
        if (rho.getItem(0)!=this.getItem(0)){
            return false;
        }

        boolean answer = true;

        int len1 = this.getLength();
        int len2 = rho.getLength();

        MyString ls1 = len1 < len2 ? this : rho;
        MyString ls2 = len1 < len2 ? rho : this;

        for (int i = ls1.getLength(); i < ls2.getLength(); ++i) {
            ls1 = ls1.addToBegin('0');
        }

        for (int i = 0; i < ls2.getLength(); i++) {
            if (ls2.getItem(i) != ls1.getItem(i))
            {
                answer = false;
            }
        }

        return answer;
    }
}
