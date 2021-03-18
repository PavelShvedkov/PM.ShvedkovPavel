//2.    Прочитать текст Java-программы и все слова public в
//      объявлении атрибутов и методов класса заменить на слово private.

package com.company;

public class RefactorCode {
    public static String refactorCode(String data, String target,String replacement){
      data.replaceAll("(?<!\\S)"+target,"(?<!\\S)"+replacement);
     return "none";
    }
}
