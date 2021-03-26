package by.bsu.lab5task2.WriteText;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;

public class TextWriter {
    public TextWriter() {
    }

    public void WriteTextInFile(String data, String filename) throws FileNotFoundException {
        try {
            PrintStream writer = new PrintStream(new FileOutputStream(filename, true));

            try {
                writer.print(data);
            } catch (Throwable var7) {
                try {
                    writer.close();
                } catch (Throwable var6) {
                    var7.addSuppressed(var6);
                }

                throw var7;
            }

            writer.close();
        } catch (IOException var8) {
            var8.printStackTrace();
        }

    }

    public void WriteTextInConsole(String data) {
        System.out.println(data);
    }
}
