import java.util.ArrayList;
import java.util.Arrays;

class LeftRecursion {
    final static String production = "A=Ab|c";
    final static String A = "A'";
    final static String eps = "eps";
    static ArrayList<String> alpha = new ArrayList<>();
    static ArrayList<String> beta = new ArrayList<>();

    static String[] getProductions(String s){
        String arr[] = s.split("\\||=");
        return arr;
    }

    static boolean checkLR(String arr[]){
        String lhs = arr[0];
        boolean bool = false;
        for(int j=1; j<arr.length; j++){
            if(lhs.charAt(0) == arr[j].charAt(0)){
                alpha.add(arr[j].substring(1));
                bool = true;
            }
            else{
                beta.add(arr[j]);
            }
        }
        return bool;
    }

    static void print(String s){
    System.out.println(s);
    }

    public static void main(String[] args) {
        String arr[] = getProductions(production);
        print(Arrays.toString(arr));
        if(checkLR(arr)){
            print("Yes left recursion exists");
            for(int i=0; i<beta.size(); i++){
                print(arr[0] + "=" + beta.get(i) + A);
            }

            String s = A+"=";
            for(int i=0; i<alpha.size(); i++){
                s = s + alpha.get(i) + A + "|";
            }
            
            print(s + eps);
        }
        else{
            print("No");
        }
    }

}
