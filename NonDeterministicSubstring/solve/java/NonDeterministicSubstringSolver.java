import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class NonDeterministicSubstringSolver {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        String A = (String) reader.next(String.class);
        reader.next();
        
        String B = (String) reader.next(String.class);
        reader.close();

        NonDeterministicSubstring solver = new NonDeterministicSubstring();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.ways(A, B));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }
}
