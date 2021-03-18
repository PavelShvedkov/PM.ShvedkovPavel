package com.company;

public class Main {

    public static void main(String[] args) {
        ReadText a=new ReadText();
        String data = a.readTextFromFile("C:/Users/pashk/source/JavaProject's/Lab5Task2/src/com/company/CodeExample.txt");
        System.out.println(RefactorCode.refactorCode("hi","hi","hi"));
    }
}
