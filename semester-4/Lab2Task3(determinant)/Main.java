package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int[][] source=new int[][] {{1,1},{2,0}};
	SquareMatrix mrx=new SquareMatrix(4);
	mrx.fillRandomMrx(3);
	mrx.displayMatrix();

	System.out.println("Determinant = "+ SquareMatrix.determinant(mrx));
	mrx.displayMatrix();
    }
}
