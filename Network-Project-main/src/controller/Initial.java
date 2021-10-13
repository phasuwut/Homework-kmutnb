package controller;

public class Initial  {
    public static void main(String[] args) {
        int ascii = 65;
        FileReader r = new FileReader();

        for(; ascii <= 70; ascii++){
            r.readFile("Router_"+ (char)ascii +".txt");
        }

    }
}
