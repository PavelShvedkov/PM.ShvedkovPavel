package by.bsu.lab5task2.CodeEditor;


public class CodeEditor {
    public CodeEditor() {
    }

    public String editCode(String data, String target, String replacement) {
        if(data!=null){
          data=  data.replaceAll(target+" ", replacement+" ");
        }
        return data;
    }
}
