import java.io.*;
// import java.net.InetAddress;
public class subnet{
public static void main(String[] args) throws IOException{ 
    System.out.println("Enter IP Address:");
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String ip = br.readLine();
    String checkclass = ip.substring(0,3); 
    int cc = Integer.parseInt(checkclass); 
    String mask = null;
    if(cc>0 && cc<224){
        if(cc<=127){
            System.out.println("IP Address is of ClassA");mask="255.0.0.0";
        }
        if(cc>=128 && cc<=191){
            System.out.println("IP Address is of ClassB");mask="255.255.0.0";
        }
        if(cc>=192 && cc<=223){
            System.out.println("IP Address is of ClassC");mask="255.255.255.0";
        }
        if(cc>=224){
            System.out.println("IP Address is used for Multicasting or reserved");
        }
    }
    System.out.println("SubnetMask:\n"+mask);
    String networkAddr="";
    String[] ipAddrParts =ip.split("\\."); 
    String[] maskParts =mask.split("\\.");
    for(int i=0;i<=3;i++){
        int x =Integer.parseInt(ipAddrParts[i]);
        int y= Integer.parseInt(maskParts[i]);
        int z = x & y;
        networkAddr += z+".";
    }
    System.out.println("SUBNET Address:\n"+networkAddr);
    }
}
