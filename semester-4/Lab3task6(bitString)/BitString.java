package com.company;


public class BitString extends MyString{
public BitString(){
    super();
}
public BitString(char[] source){
    super(source);

    if (source[0]=='1'){
       this.array= (addCode(source)).array;
    }
    if (!isBitString(source)) {
      this.array=null;
      this.length=0;
    }
}
public BitString(MyString source){
    String message=new String("Source string ");

    if(isBitString(source.array))
    {
        length=source.getLength();
        array=source.array.clone();
    } else {
        if ((source.getLength() <= 0)) {
            System.out.println(message + "empty");
        } else {
            System.out.println(message + "not bit");
        }
        length=0;
        array=new char[0];
    }
}

public BitString add(BitString rho){

    int len1 = this.getLength();
    int len2 = rho.getLength();

    if (len1<=0||len2<=0)
    {
        BitString buffer=new BitString();
        if (len1<=0)
        {
			 buffer=rho;
        }
        else
        {
            if (len2<=0)
            {
				 buffer=this;
            }
        }

        return buffer;
    }

    MyString ls1 = new MyString(rho);
    MyString ls2 =  this;
    MyString result=new BitString();

    int carry = 0;

    for (int i = ls2.getLength() - 1; i >= 0; --i)
    {
        int bit1 = ls1.getItem(i) - '0'; // '0' => 0, '1' => 1
        int bit2 = ls2.getItem(i) - '0';
        char sum = (char)((bit1 ^ bit2 ^ carry) + '0');
        result = result.addToBegin(sum);
        carry = (bit1 & carry) | (bit2 & carry) | (bit1 & bit2);
    }

    if (carry!=0)
    {
        result =  result.addToBegin('1');
    }

    BitString buffer=new BitString(result);

    return buffer;
};
public boolean areEqual(BitString rho){
    boolean answer=true;

    if(this.getLength()!= rho.getLength()){
        answer=false;
    } else{
        int maxLength=(this.getLength()> rho.getLength()?this.getLength(): rho.getLength());
        for (int i=maxLength;i>=0;--i){
            if(this.getItem(i)!=getItem(i)){
                answer=false;
            }
        }
    }


    return true;
};
    private static BitString addCode(char[] source){
        int length = source.length;
        char[] buffer = new char[length];
        buffer= source.clone();

        for (int i = 0; i < length; i++)
        {
            if (source[i]=='0')
            {
                buffer[i] = '1';
            }
            else
            {
                buffer[i] = '0';
            }
        }

        for (int i = length-1; i>0; --i)
        {
            if (buffer[i] == '0')
            {
                buffer[i] = '1';
                break;
            }
            else
            {
                buffer[i] = '0';
            }
        }

        BitString result=new BitString(buffer);
        return result;
    }
    private static boolean isBitString(char[] source){
    boolean result=true;

    for (int i=0;i<source.length;++i){
        if (source[i]!='0'&&source[i]!='1') {
            result=false;
        }
    }

    return result;
    }
}
