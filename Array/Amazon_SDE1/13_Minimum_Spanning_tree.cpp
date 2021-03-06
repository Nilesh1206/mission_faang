// import java.util.*;


/*
Your team at amazon is overseeing the design of a new high-efficiency data center at HQ2. A power grid need to be generated for supplying power to N servers. All servers in the grid have to be connected such that they have access to power. The cost of connections between different servers varies.

Assume that there are no ties, names of servers are unique, connections are directionless, there is at most one connection between a pair of servers, all costs are greater than zero, and a server does not connect to itself.

Write an algorithm to minimize the cost of connecting all servers in the power grid.

Input
two arguments - num, an Integer representing number of connections.
connectons, representing a list of connections where each element of the list consists of two servers and the cost of connection between the servers.




*/


class Connection{
	char from, to;
	int cost;
	Connection(char from, char to, int cost){
		this.from = from;
		this.to = to;
		this.cost = cost;
	}
}

class Node{
	int data;
	Node parent;
	Node(int data){
		this.data = data;
		this.parent = this;
	}
}

class MinimumConnectionCost
{
	public static boolean isValid(int i, int size){
		if(i < 0 || i >= size){
			return false;
		}
		return true;
	}
		
	public static void heapify(ArrayList<Connection> heap, int i){
		if(i >= heap.size()){
			return ;
		}
		int lChild = 2 * i + 1;
		int rChild = 2* i + 2;
		if(isValid(lChild, heap.size()) && isValid(rChild, heap.size())){
			if(heap.get(lChild).cost <= heap.get(rChild).cost){
				if(heap.get(lChild).cost < heap.get(i).cost){
					Connection temp = heap.get(lChild);
					heap.set(lChild, heap.get(i));
					heap.set(i, temp);
					heapify(heap, lChild);
				}
			}
			else{
				if(heap.get(rChild).cost < heap.get(i).cost){
					Connection temp = heap.get(rChild);
					heap.set(rChild, heap.get(i));
					heap.set(i, temp);
					heapify(heap, rChild);
				}
			}
		}
		else if(isValid(lChild, heap.size())){
			if(heap.get(lChild).cost < heap.get(i).cost){
				Connection temp = heap.get(lChild);
				heap.set(lChild, heap.get(i));
				heap.set(i, temp);
				heapify(heap, lChild);
			}
		}
		else if(isValid(rChild, heap.size())){
			if(heap.get(rChild).cost < heap.get(i).cost){
				Connection temp = heap.get(rChild);
				heap.set(rChild, heap.get(i));
				heap.set(i, temp);
				heapify(heap, rChild);
			}
		}
		return ;
	}
	
	public static void formHeap(ArrayList<Connection> heap){
		for(int i=heap.size()/2;i>=0;i--){
			heapify(heap, i);
		}
		return ;
	}
	
	public static Connection extractMin(ArrayList<Connection> heap){
		Connection temp = heap.get(0);
		heap.set(0, heap.get(heap.size() - 1));
		heap.remove(heap.size() - 1);
		heapify(heap, 0);
		return temp;
	}
	
	public static Node findParent(Node node, ArrayList<Node> path){
		if(node.parent == node){
			for(int i=0;i<path.size();i++){
				path.get(i).parent = node;
			}
			return node;
		}
		path.add(node);
		return findParent(node.parent, path);
	}
	
	public static ArrayList<Connection> findMinimumCostToConnectServers(ArrayList<Connection> heap){
		ArrayList<Connection> res = new ArrayList<> ();
		
		formHeap(heap);
		
		Node node[] = new Node[26];
		for(int i=0;i<26;i++){
			node[i] = new Node(i);
		}
		
		while(heap.size() > 0){
			Connection ele = extractMin(heap);
			
			Node parentFrom = findParent(node[ele.from - 'A'], new ArrayList<> ());
			Node parentTo = findParent(node[ele.to - 'A'], new ArrayList<> ());
			
			if(parentFrom != parentTo){
				parentTo.parent = parentFrom;
				res.add(new Connection(ele.from, ele.to, ele.cost));
			}
		}
		return res;
	}
	
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		ArrayList<Connection> a = new ArrayList<> ();
		for(int i=0;i<n;i++){
			a.add(new Connection(sc.next().charAt(0), sc.next().charAt(0), sc.nextInt()));
		}
		ArrayList<Connection> ans = findMinimumCostToConnectServers(a);
		for(int i=0;i<ans.size();i++){
			System.out.println(ans.get(i).from+" "+ans.get(i).to+" "+ans.get(i).cost);
		}
	}
}