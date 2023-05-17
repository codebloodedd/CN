import java.util.Scanner;

public class DistanceVectorRouting {
    public static void main(String[] args) {
        char ch;
        int m = 12;
        int n = 4;
        int intialDelay[][] = new int[][]{
                { 0, 24, 20, 21 },
                { 12, 36, 31, 28 },
                { 25, 18, 19, 36 },
                { 40, 27, 8, 24 },
                { 14, 7, 30, 22 },
                { 23, 20, 19, 40 },
                { 18, 31, 6, 31 },
                { 17, 20, 0, 19 },
                { 21, 0, 14, 22 },
                { 9, 11, 7, 10 },
                { 24, 22, 22, 0 },
                { 29, 33, 9, 9 }
        };
    
        int refreshDelay[] = new int[]{8,10,12,6};
        int tempArray[] = new int[4];
        int minValue[] = new int[12];
        int minIndex[] = new int[12];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                tempArray[j] = intialDelay[i][j] + refreshDelay[j]; 
            }
            minValue[i] = tempArray[0];
            for(int j=0;j<n;j++){
                if (minValue[i]>=tempArray[j]) {
                    minValue[i] = tempArray[j];
                    minIndex[i] = j;
                }
            }
            System.out.print(minValue[i]+"\t");
            switch(minIndex[i]){
                case 0:
                    System.out.print("A");
                    break;
                case 1:
                    System.out.println("I");
                    break;
                case 2:
                    System.out.println("H");
                    break;
                case 3:
                    System.out.println("K");
                    break;
                default:
                    break;
            }
            System.out.println("\n");
        }
        
    }
}