import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class bracketMatcherClass {

	public static void main(String args[]) {
		System.out.println(
				bracketMatcher(args[0])
				);
	}
	
	public static boolean bracketMatcher(String sequence) {
		// create new stack
	    Stack<Character> stack = new Stack<>();  
	    // create character map that maps closing bracket to associated opening bracket
	    Map<Character, Character> map = new HashMap<Character, Character>();
	    
	    // add the mappings
	    map.put('}', '{');
	    map.put(')', '(');
	    map.put(']', '[');
	    
	    
	    // loop over chars in sequence
	    for (char c : sequence.toCharArray()) {
	    	// if the stack is empty then simply push the character to the top
	    	if (stack.empty()) {
	    		// this is only true for closing brackets
	    		if (map.get(c) != null) {
	    			// then we have an invalid sequence 
	    			// as there cannot have a closing bracket with no opening bracket
	    			return false; 
	    		}else {
	    			stack.push(c);
	    		}
	    	} else {
	    		// if the top item of the stack has an accepted closing bracket
	    		if (stack.peek() == map.get(c)) {
	    			// pop the top item
	    			stack.pop();
	    		} else {
	    			// else push to the top of the stack
	    			stack.push(c);
	    		}
	    	}
	    }
	   
	    // if the stack is empty we have a valid sequence, so true is returned
	    // else return false
	    return stack.empty();
	 
	}
}
