

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		Map<String,Equipo> ls = new HashMap<>();
		int t=0,g=0;
		boolean flag=false;
		//System.out.println();
		while(true) {
			
			try {
				String a = br.readLine();
				String []b = a.split(" ");
				t=Integer.parseInt(b[0]);
				g=Integer.parseInt(b[1]);
				if(t==0) break;
				if(!flag)flag=true;
				else System.out.println();
			} catch (IOException e) {
				System.err.println(e);
			}
			for (int i = 0; i < t; i++) {
				try {
					String cad = br.readLine();
					ls.put(cad, new Equipo(cad));
				} catch (IOException e) {
					System.err.println(e);
				}
			}
			for (int i = 0; i < g; i++) {
				try {
					String cad = br.readLine();
					String[]cads = cad.split(" ");
					Equipo e = ls.get(cads[0]);
					Equipo f = ls.get(cads[4]);
					int golesa,golesb;
					golesa = Integer.parseInt(cads[1]);
					golesb = Integer.parseInt(cads[3]);
					e.ga += golesa;
					e.gr += golesb;
					f.ga += golesb;
					f.gr += golesa;
					e.pj +=1;
					f.pj +=1;
					if(golesa==golesb) {
						e.pts+=1;
						f.pts+=1;
					}else if(golesa>golesb) {
						e.pts +=3;
					}else {
						f.pts +=3;
					}
					
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			Equipo []lss =  ls.values().toArray(new Equipo[0]);
			Arrays.sort(lss,new sortEquipo());
			int i=1,a=-1,b=-1,c=-1;
			//String aux="                ",cpts,cpj,cga,cgr,gd,ci;
			for (Equipo e : lss) {
				//int lim = 15-e.nombre.length();
				String prom;
				if(e.pj!=0) {
				
					prom= new DecimalFormat("0.00").format(e.pts*1.0/(e.pj*3)*100);
				}else {
					prom ="N/A";
				}
				
				String id = new DecimalFormat("##.").format(i);
				if(a==e.pts && b==e.ga-e.gr && c==e.ga) {
					System.out.printf("   %16s%4d%4d%4d%4d%4d%7s\n",e.nombre,e.pts,e.pj,e.ga,e.gr,(e.ga-e.gr),prom);
				}else {
					System.out.printf("%3s%16s%4d%4d%4d%4d%4d%7s\n",id,e.nombre,e.pts,e.pj,e.ga,e.gr,(e.ga-e.gr),prom);
				}
				i++;
				a = e.pts;b=e.ga-e.gr;c=e.ga;
			}
			System.out.flush();
			ls.clear();
		}
		
	}

}
class sortEquipo implements Comparator<Equipo>{
	
	@Override
	public int compare(Equipo e1, Equipo e2) {
		int gd = e1.ga - e1.gr;
		int gd2 = e2.ga - e2.gr;
		
		if(e1.pts!=e2.pts) {
			return e2.pts-e1.pts;
		}else if(gd!=gd2) {
			return gd2-gd;
		}else if(e1.ga!=e2.ga){
			return e2.ga-e1.ga;
		}
		else {
			String aux1=e1.nombre.toLowerCase(),aux2=e2.nombre.toLowerCase();
			//if(aux1.equals(aux2)) {
				//return e1.nombre.compareTo(e2.nombre);
			//}else {
				return aux1.compareTo(aux2);
			//}
		}
			
	}

	
	
}
class Equipo{
	public String nombre;
	public int pts;
	public int pj;
	public int ga;
	public int gr;
	public Equipo(String nom){
		nombre=nom;
		pts=pj=ga=gr=0;
	}
	
	
}
