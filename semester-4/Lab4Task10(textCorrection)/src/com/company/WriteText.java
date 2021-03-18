package com.company;

import java.io.*;

public class WriteText {
    public void WriteTextInFile(String data,String filename) throws FileNotFoundException{
        try(PrintStream writer = new PrintStream(new FileOutputStream(filename, true))) {
        writer.print(data);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void WriteTextInConsole(String data){
        System.out.println(data);
    }
}
