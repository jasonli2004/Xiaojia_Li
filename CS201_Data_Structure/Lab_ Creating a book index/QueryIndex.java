
import java.io.*;
import java.util.*;

public class QueryIndex {
	private static HashSet<String> readExcludeList(String fileName) throws FileNotFoundException {

		HashSet<String> excludeList = new HashSet<String>();

		Scanner excludeFile = new Scanner(new FileInputStream(fileName));
		while (excludeFile.hasNext()) {
			String s = excludeFile.next();
			excludeList.add(s);
		}
		
		excludeFile.close();
		return excludeList;
	}

	private static HashMap<String,ArrayList<Integer>> createIndex(String fileName, HashSet<String> excludeList) throws FileNotFoundException {

		HashMap<String,ArrayList<Integer>> st = new HashMap<String,ArrayList<Integer>>();
		
		Scanner text = new Scanner(new FileInputStream(fileName));
		int page = 1;
		while (text.hasNext()) {
			String word = text.next();
			if (word.equals( "-----")){
				page++;
			}
			else if(excludeList.contains(word)){
			}
			else if (!st.containsKey(word)){
				ArrayList<Integer> temp = new ArrayList<Integer>();
				temp.add(page);
				st.put(word, temp);
			}
			else{
				ArrayList<Integer> c = st.get(word);
				if (!c.contains(page)){
					c.add(page);
				}
			}
			// if the word is "-----", increment the page count
			// if the word is in the exclude list, ignore it
			// if the word not in the symbol table, create a new entry for it
			// if the word is in the symbol table, add this page to its list of pages
		}
		
		text.close();
		
		return st;
	}

	public static void main(String[] args) throws FileNotFoundException {

		Scanner scnr = new Scanner(System.in);

		HashSet<String> excludeList = readExcludeList("exclude.txt");
		HashMap<String, ArrayList<Integer>> st = createIndex("paginatedtale.txt", excludeList);
		
//		System.out.println("Index created - enter query word");
		
		while (scnr.hasNext()) {
			String word = scnr.next();
			System.out.print(word+": ");
			if (excludeList.contains(word)){
				System.out.println("Excluded from search.");
			}
			else if(!st.containsKey(word)){
				System.out.println("Not in text.");
			}
			else{
				for (int j: st.get(word)){
					System.out.print(j + " ");
				}
				System.out.println();
			}
			// if the word is in the exclusion list
			//		print "Excluded from search."
			// else if the word is not in the text
			//		print "Not in text."
			// else
			//		print the list of page numbers
			//		use System.out.print(pageNumber + " ")
			//		followed by System.out.println() when done
		}
		
		scnr.close();
	}
}
	