package com.company;

public class RemovePartOfText {
    public String removePartBetweenSymbols(String data, char symbol) {
        String result = data;
        char[] buffer;

        int openingSymbol = data.indexOf(symbol);
        int repeatOpeningSymbol = data.indexOf(symbol, openingSymbol + 1);
        int coveringSymbol;

        switch (symbol) {
            case '(':
                coveringSymbol = data.indexOf(symbol + 1);
                break;
            case '[', '{':
                coveringSymbol = data.indexOf(symbol + 2);
                break;
            default:
                coveringSymbol = repeatOpeningSymbol;
                repeatOpeningSymbol = 0;
                break;
        }

        while(repeatOpeningSymbol < coveringSymbol && repeatOpeningSymbol > 0) {
            openingSymbol = repeatOpeningSymbol;
            repeatOpeningSymbol = data.indexOf(symbol, openingSymbol+1);
        }

        if(coveringSymbol>=openingSymbol&&openingSymbol!=-1) {
            buffer = new char[coveringSymbol - openingSymbol + 1];
            data.getChars(openingSymbol, coveringSymbol + 1, buffer, 0);
            String targetWord = new String(buffer);
            result = result.replace(targetWord, "");
    }

        return result;
    }
}
