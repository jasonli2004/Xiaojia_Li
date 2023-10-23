import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

public class Graph{
   private ArrayList<Integer>[] adjVertices;
   private int numEdges = 0;
   private boolean isDirected = false;
   private boolean marked[];
   private int[] edgeFrom;
   private Queue<Integer> q;

   @SuppressWarnings("unchecked")
   public Graph(int numVertices){
      adjVertices = (ArrayList<Integer>[]) new ArrayList[numVertices];
      marked = new boolean[numVertices];
      for (int i = 0; i < numVertices; i++){
         adjVertices[i] = new ArrayList<Integer>();
      }
   }
   public int numVertices(){
      return adjVertices.length;
   }

   public int numEdges(){
      return numEdges;
   }
   public void addEdge(int v, int w){
      adjVertices[v].add(w);
      if (!isDirected){
         adjVertices[w].add(v);
      }
      numEdges++;
   }

   public Iterable<Integer> adj(int v){
      return adjVertices[v];
   }

   public void dfs(Graph g, int v){
      marked[v] = true;
      for (int w : g.adj(v)){
         if(!marked[w]){
            edgeFrom[w] = v;
            System.out.println(w);
            dfs(g, w);
         }
      }
   }
   public void dfs(int v){
      dfs(this, v);
   }

   public void DepthFirstPath(Graph g, int v){
      edgeFrom = new int[g.numVertices()];
      marked = new boolean[g.numVertices()];
      dfs(g,v);
   }

   public void bfs(Graph g, int v){
      q = new LinkedList<Integer>();
      marked[v] = true;
      q.add(v);
      while (!q.isEmpty()){
         v = q.remove();
         for (int w: this.adj(v)){
            if (!marked[w]){
               marked[w] = true;
               edgeFrom[w] = v;
               q.add(w);
            }
         }
      }
   }

   public boolean hasPathTo(int v){
      return marked[v];
   }

   

   public static void main(String args[]){
      Graph a = new Graph(3);
      a.addEdge(1, 2);
      a.addEdge(0, 2);
      a.addEdge(0, 1);
     // System.out.println(a.numEdges());
      System.out.println(a.adj(1));
      a.dfs(0);      
   }

}