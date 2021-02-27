package com.company;

import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        int n=0;

        System.out.print("Enter number of strings: ");
        n=input.nextInt();

        String[] array=new String[n];
	    array=  enterWords(n);

	    int maxLength=0;
	    String largestWord="";

	    for (int i=0;i<n;++i){
	        if(maxLength<array[i].length()) {
                maxLength = array[i].length();
                largestWord = array[i];
            }
        }

	    System.out.println("Largest word is "+largestWord+" and its lenth equal to "+maxLength);
    }

    public static String[] enterWords(int n) {
        Scanner input=new Scanner(System.in);
        String[] array=new String[n];

        for (int i=0;i<n;++i) {
            System.out.print("Enter "+(i+1)+" string: ");
            array[i]= input.nextLine();
        }

        return array;
    }
}
