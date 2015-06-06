import java.io.File;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;


public class Q107 {

	public static void main(String[] args) throws Exception {
		long start = System.currentTimeMillis();
		Scanner reader = new Scanner(new File("network.txt"));
		List<Node> allnode = new ArrayList<Node>();
		for(int i = 0; i < 40; i++) {
			Node currentnode = new Node(i);
			allnode.add(currentnode);
		}			
		int currentnode = 0;
		List<Connection> connections = new ArrayList<Connection>();
		
		int totalweight = 0;
		while(reader.hasNext()) {
			String[] line = reader.nextLine().split(",");
			Node first = allnode.get(currentnode);
			for(int i = currentnode+1; i < line.length; i++) {
				if(!line[i].equals("-")) {
					int weight = Integer.parseInt(line[i]);
					totalweight += weight;
					Node second = allnode.get(i);
					Connection newconnect = new Connection(first, second, weight);
					connections.add(newconnect);
				}
			}
			currentnode++;
		}
		reader.close();
		Collections.sort(connections);
		int minimized = 0;
		Iterator<Connection> itr = connections.iterator();
		while(!statuscheck(allnode)) {
			Connection currentcon = itr.next();
			Node[] nodes = currentcon.getNodes();
			if(nodes[0].connected(nodes[1]))
				continue;
			else {
				minimized += currentcon.getWeight();
				nodes[0].addConnect(nodes[1]);
			}
		}
		long end = System.currentTimeMillis();
		System.out.println(totalweight - minimized);
		System.out.println(end - start);
	}
	
	public static boolean statuscheck(List<Node> allnodes) {
		return allnodes.get(0).getConnections().size() == 40;
	}

}
