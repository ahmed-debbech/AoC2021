import java.io.*;
import java.util.regex.*;  
import java.util.*;

class fold{
    public int coord;
    public char axe;
    public fold(int coord, char axe){
        this.coord = coord;
        this.axe = axe;
    }
    @Override
    public String toString(){
        return "coord: " + this.coord + " axe: " + this.axe;
    }
}
class part2{
    public static char[][] getNew(int maxCols, int maxRows){
        char[][] points = new char[maxRows][maxCols];
        for(int i=0; i<maxRows; i++){
            for(int j=0; j<maxCols; j++){
                points[i][j] = '.';
            }
        }
        return points;
    }
    public static void show(char points[][]){
        for(int i =0; i<maxRows; i++){
            for(int j=0; j<maxCols; j++){
                System.out.print(points[i][j]);
            }
            System.out.println();
        }
    }
    public static int maxCols = 1311;
    public static int maxRows = 895;


    public static void main(String [] args){
        File file = new File("input"); 
        try{
        BufferedReader br = new BufferedReader(new FileReader(file)); 
        String st;
        char[][] points = part2.getNew(maxCols, maxRows);
        List<fold> folds = new ArrayList<>();
        while ((st = br.readLine()) != null) {
        //System.out.println(st);
            //Scanner sc = new Scanner(st);
            Pattern r = Pattern.compile("(\\d{4}|\\d{3}|\\d{2}|\\d{1}),(\\d{4}|\\d{3}|\\d{2}|\\d{1})");
            Matcher m = r.matcher(st);
            if(m.find()){
                String x = m.group(1);
                String y = m.group(2);
                System.out.println(x + " " +  y);
                int xx = Integer.parseInt(x);
                int yy = Integer.parseInt(y);
                points[yy][xx] = '#';
            }else{
                Pattern rr = Pattern.compile("(fold along )(x|y)=(\\d{4}|\\d{3}|\\d{2}|\\d{1})");
                Matcher mm = rr.matcher(st);
                if(mm.find()){
                    System.out.println(mm.group(2) + "  " + mm.group(3));
                    folds.add(new fold(Integer.parseInt(mm.group(3)), mm.group(2).charAt(0)));
                }else{
                    System.out.println("no match");
                }
            }
        }
        part2.show(points);

        System.out.println(folds.toString());

        //get the first fold
        int inverse = 0;
        char [][] points1;
        for(int h=0; h<=folds.size()-1; h++){
            if(folds.get(h).axe == 'y'){
                points1 = part2.getNew(maxCols, maxRows);
                int div = folds.get(h).coord;
                inverse = div;
                for(int i = div; i>=0; i--){
                    for(int j=0; j<maxCols; j++){
                        if((points[i][j] == '#') || (points[inverse][j] == '#')){
                            points1[i][j] = '#';
                        }
                    }
                    inverse++;
                }
                maxRows = div;
                points = points1;
            }else{
                points1 = part2.getNew(maxCols, maxRows);
                int div = folds.get(h).coord;
                inverse = div;
                for(int i = div; i>=0; i--){
                    for(int j=0; j<maxRows; j++){
                        if((points[j][i] == '#') || (points[j][inverse] == '#')){
                            points1[j][i] = '#';
                        }
                    }
                    inverse++;
                }
                maxCols = div;
                points = points1;
            }
            System.out.println("ITERATION ==============");
            part2.show(points);
        }

        int numPoints = 0;
        for(int i =0; i<maxRows; i++){
            for(int j=0; j<maxCols; j++){
                if(points[i][j] == '#'){
                    numPoints++;
                }
            }
        }
        System.out.println("RESULT: "+ numPoints);

        }catch(FileNotFoundException exp){
            System.out.println("no file named with that name");
        }catch(IOException ex){
            System.out.println("could not open file");
        }
    }
}