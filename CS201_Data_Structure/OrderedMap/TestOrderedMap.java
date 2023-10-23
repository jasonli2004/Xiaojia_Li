import java.util.Scanner;

// This program tests an implemention of OrderedMap, with
// type parameters Key=String and Value=Integer.  The input
// starts with an integer specifying the maximum number of
// elements in the map.  After that, each line is one of
// the following:
//
//  put S N         -- adds a mapping of S to N
//  get S           -- returns the integer which S maps to
//  contains S      -- determines if S has a mapping
//  min             -- gets the value of the minimum key
//  max             -- gets the value of the maximum key

public class TestOrderedMap {
    
    private static void testStrStrMap() {
        Map<String,String> map = new OrderedMap<String,String>(10);
        map.put("author1", "Sedgewick");
        map.put("author2", "Wayne");
        map.put("ISBN", "978-0-321-57351-3");
        System.out.println(map);
    }
    
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        
        int maxElements = sc.nextInt();
        Map<String,Integer> map = new OrderedMap<String,Integer>(maxElements);
        if (map.size() != 0)
            System.out.println("size() returned non-zero value for a new map");
        if (!map.isEmpty())
            System.out.println("isEmpty() returned false for a new map");

        while (sc.hasNext()) {
            String command = sc.next();
            if (command.equals("put")) {
                String key = sc.next();
                int value = sc.nextInt();
                map.put(key, value);
                System.out.printf("Added (\"%s\",%d), new size is %d\n", key, value, map.size());
                if (map.isEmpty())
                    System.out.println("isEmpty() returned true for a map with an entry");
                } else if (command.equals("get")) {
                String key = sc.next();
                int value = map.get(key);
                System.out.printf("\"%s\" maps to %d\n", key, value);
            } else if (command.equals("contains")) {
                String key = sc.next();
                boolean b = map.contains(key);
                System.out.printf("\"%s\" is%s in the map\n", key, b ? "" : " not");
            } else if (command.equals("minmax")) {
                String minKey = map.minKey();
                String maxKey = map.maxKey();
                System.out.printf("The minimum key is %s, with value %s\n", minKey, map.get(minKey));
                System.out.printf("The maximum key is %s, with value %s\n", maxKey, map.get(maxKey));
            } else if (command.equals("print")) {
                System.out.println(map);
            } else if (command.equals("strstrmap")) {
                testStrStrMap();
            }
        }

        sc.close();
    }
}
