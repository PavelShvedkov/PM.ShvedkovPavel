package com.company;
import java.util.Scanner;

public class SquareMatrix {
    public SquareMatrix() {
      n=0;
      array=null;
  }
    public SquareMatrix(int size) {
        if(size<=0){
            System.out.println("Invalid size of Matrix. Size must be more zero");
            n=0;
            return;
        }
        n=size;
        array=new int[n][n];
    }
    public SquareMatrix(int[][] matrix,int size){
        if(size<=0){
            System.out.println("Invalid size of Matrix. Size must be more zero");
            n=0;
            return;
        } else{
            n=size;
            array=new int[n][n];
        }
        if(matrix==null){
            System.out.println("Source matrix is empty");
            return;
        }

        for (int i=0;i<n;++i) {
            for (int j = 0; j < n; ++j) {
                array[i][j] = matrix[i][j];
            }
        }
    }
    public SquareMatrix(SquareMatrix other){
        this(other.getMatrix(),other.getSize());
    }

    public int getSize(){
        return n;
    }
    public int getItem(int row, int column){
        if (row>=n||column>=n)
        {
            System.out.println("Invalid index of element. Index must be less "+n);
            return 0;
        }
        if (row<0||column<0)
        {
            System.out.println("Invalid index of element. Index must be more zero");
            return 0;
        }

        return array[row][column];
    }
    public int[][] getMatrix(){
        int[][] matrix=new int[n][n];

        for (int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                matrix[i][j]=array[i][j];
            }
        }

        return matrix;
    }
    public SquareMatrix getMinor(int row,int column){
        if(row>=n||column>=n){
            System.out.println("Invalid index. Index must be least "+n);
            return this;
        }
        if(row<0||column<0){
            System.out.println("Invalid index. Index must be more zero");
            return this;
        }

        int newSize=this.getSize()-1;
        int[][] buffer=new int[newSize][newSize];

        for (int i=0,k=0;i<n;++i){
            if(i==row){
                continue;
            }

            for(int j=0,l=0;j<n;++j){
                if(j==column){
                    continue;
                }

                buffer[k][l]=array[i][j];
                ++l;
            }
            ++k;
        }

        SquareMatrix result=new SquareMatrix(buffer,newSize);

        return result;
    }

    public void fillMatrix(Scanner in) {
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                System.out.print("Enter element "+(i+1)+" row, "+(j+1)+" column: ");
                array[i][j]=in.nextInt();
            }
        }
    }
    public void fillRandomMrx(int maxElement){
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                array[i][j]=(int)(Math.random()*100000)%maxElement;
            }
        }
    }
    public void displayMatrix(){
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                System.out.print(array[i][j]+" ");
            }
            System.out.print("\n");
        }
    }
    public static int determinant(SquareMatrix matrix){
        int result=0;
        int size=matrix.getSize();

        if (size==1){
            return matrix.getItem(0,0);
        }

        for(int i=0;i<matrix.getSize();++i){
            result+=Math.pow(-1,i)*matrix.getItem(0,i)*determinant(matrix.getMinor(0,i));
        }

        return result;
    }

    private int n;
    private int array[][];
}
