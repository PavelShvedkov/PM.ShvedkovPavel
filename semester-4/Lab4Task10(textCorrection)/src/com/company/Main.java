package com.company;

import java.awt.*;
import java.io.FileNotFoundException;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        ReadText text=new ReadText();
        WriteText textOut=new WriteText();
        RemovePartOfText app=new RemovePartOfText();
       try {
           String data = text.readTextFromFile("C:/Users/pashk/source/JavaProject's/Lab4Task10/src/com/company/testText");
           textOut.WriteTextInFile( app.removePartBetweenSymbols(data,'['),"C:/Users/pashk/source/JavaProject's/Lab4Task10/src/com/company/testText");
       } catch (FileNotFoundException e){
           e.printStackTrace();
       }
    }
}
