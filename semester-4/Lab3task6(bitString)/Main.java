package com.company;

public class Main {

    public static void main(String[] args) {
       char[] b=new char[]{'H','e','l','l','o','!'};
       char[] d=new char[]{'0','0','1','0','1','0','1','0'};
        char[] e=new char[]{'1','1','0','1','0','1','1','0'};
        MyString c=new MyString(b);
        BitString a=new BitString(d);
        BitString f=new BitString(e);

       a= a.add(f);
        a.displayMyString();
        a.clear();
        a.displayMyString();
    }
}
