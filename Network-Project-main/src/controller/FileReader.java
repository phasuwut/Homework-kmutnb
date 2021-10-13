package controller;

import java.io.File;  // Import the File class
//import java.io.FileInputStream;
import java.io.FileNotFoundException;  // Import this class to handle errors
import java.util.Scanner; // Import the Scanner class to read text files

public class FileReader {
//    public static void main(String[] args) {

        public void readFile(String filename){
            try {

                File  myObj = new File (filename);
                Scanner myReader = new Scanner(myObj);
                String filename_ = myObj.getName().replace(".","=");
                System.out.printf("|                    %-41s|\n", "Routing Table in " + filename_.split("=")[0]);
                System.out.println("|   destination subnet   |   next router   |   hops to dest   |");

                while (myReader.hasNextLine()) {
                    String data = myReader.nextLine();
                    System.out.printf("|       %-17s|       %-10s|         %-9s|\n", data.split(":")[0],data.split(":")[1],data.split(":")[2]);
                }
                System.out.println("");

                myReader.close();
            } catch (FileNotFoundException e) {
                System.out.println("An error occurred.");
                e.printStackTrace();
            }
        }
//    }
}

