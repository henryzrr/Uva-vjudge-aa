package main;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		Map<String,Integer> map= new HashMap<String,Integer>();
		while(sc.hasNext()) {
			int a = sc.nextInt();
			if(a==0)break;
			
			for (int i = 0; i < a; i++) {
				int []ls=new int[5];
				for (int j = 0; j < 5; j++) {
					ls[j]=sc.nextInt();
				}
				Arrays.sort(ls);
				String cad =Arrays.toString(ls);
				//System.out.println(cad);
				if(!map.containsKey(cad)) {
					map.put(cad,1);
				}else {
					
					int aux = map.get(cad)+1;
					map.put(cad, aux);
				}
			}
			
			int max=0,cont=0;
			for(Integer i : map.values()) {
				if(i>max) {
					max=i;
					cont=1;
				}else if(max==i) {
					cont++;
				}
			}
			
			System.out.println(cont*max);
			map.clear();
		}
	}

}
