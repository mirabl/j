import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class JumpFurtherSolver {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        int N = (Integer) reader.next(Integer.class);
        reader.next();
        
        int badStep = (Integer) reader.next(Integer.class);
        reader.close();

        JumpFurther solver = new JumpFurther();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.furthest(N, badStep));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }
}
