package by.bsu.lab5task2.ReadText;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.InputMismatchException;
import java.util.Scanner;

public class TextReader {
    public String readTextFromFile(String filename) throws InputMismatchException, FileNotFoundException {
        try (Scanner in = new Scanner(new File(filename));){
            String data = new String();

            while (in.hasNextLine()) {
                data+=in.nextLine()+'\n';
            }

            return data;
        }
    }

    public String readTextFromConsole() {
        Scanner in =new Scanner(System.in);
        String data=new String();

        data+=in.nextLine();

        return data;
    }
}

