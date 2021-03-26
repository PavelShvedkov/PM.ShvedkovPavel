package by.bsu.lab5task2.Main;


import by.bsu.lab5task2.CodeEditor.CodeEditor;
import by.bsu.lab5task2.ReadText.TextReader;
import by.bsu.lab5task2.WriteText.TextWriter;

import java.io.FileNotFoundException;

public class Main {

public static void main(String[] args) {
    TextReader reader = new TextReader();
    TextWriter writer = new TextWriter();
    CodeEditor editor = new CodeEditor();

    try {
        String data = reader.readTextFromFile("data/Text.txt");
        data=editor.editCode(data,"public","private");
      writer.WriteTextInFile(data,"data/Text.txt");
       // textOut.writeTextInConsole( app.removePartBetweenSymbols(data,'@'));
    } catch (FileNotFoundException e){
        e.printStackTrace();
    }
}
}