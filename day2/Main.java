import java.io.*;
import java.util.regex.*;  
import java.util.*;

//NOTE THAT THE TWO PARTS ARE DEVIDED INTO TWO METHODS
class Main {

  public static void part1(){
    File file = new File("input"); 
    try{
      BufferedReader br = new BufferedReader(new FileReader(file)); 
      String st; 
      int dep = 0;
      int hor = 0;
      while ((st = br.readLine()) != null) {
          Scanner sc = new Scanner(st);
          Scanner direction = new Scanner(sc.next());
          Scanner value = new Scanner(sc.next());
          switch(direction.nextLine()){
              case "forward":
                hor += Integer.parseInt(value.nextLine());
              break;
              case "up":
                dep -= Integer.parseInt(value.nextLine());
              break;
              case "down":
              dep += Integer.parseInt(value.nextLine());
              break;
          }
      } 
      System.out.println("depth: " + dep);
      System.out.println("horizontal: " + hor);
      System.out.println("RESULT: " + dep * hor);
    }catch(FileNotFoundException exp){
        System.out.println("no file named with that name");
    }catch(IOException ex){
        System.out.println("could not open file");
    }
  }
  public static void part2(){
    File file = new File("input"); 
    try{
      BufferedReader br = new BufferedReader(new FileReader(file)); 
      String st; 
      int dep = 0;
      int hor = 0;
      int aim = 0;
      while ((st = br.readLine()) != null) {
          //System.out.println(st);
          Scanner sc = new Scanner(st);
          Scanner direction = new Scanner(sc.next());
          Scanner value = new Scanner(sc.next());
          //System.out.println(direction.nextLine()+value.nextLine());
          switch(direction.nextLine()){
              case "forward":
                int xx= Integer.parseInt(value.nextLine());
                hor += xx;
                dep += (xx * aim);
              break;
              case "up":
                aim -= Integer.parseInt(value.nextLine());
              break;
              case "down":
                aim += Integer.parseInt(value.nextLine());
              break;
          }
      } 
      System.out.println("depth: " + dep);
      System.out.println("horizontal: " + hor);
      System.out.println("aim: " + aim);
      System.out.println("RESULT: " + dep * hor);
    }catch(FileNotFoundException exp){
        System.out.println("no file named with that name");
    }catch(IOException ex){
        System.out.println("could not open file");
    }
  }
  public static void main(String[] args) {
    System.out.println("Hello world!");
    //uncommet a part function to execute it
    //part1();
    //part2();
  }
}
