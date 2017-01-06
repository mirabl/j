import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class TriangleEasySolver {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        int n = (Integer) reader.next(Integer.class);
        reader.next();
        
        List<Integer> xBoxed = (List<Integer>) reader.next(new TypeRef<List<Integer>>(){}.getType());
        int[] x = new int[xBoxed.size()];
        for (int _i = 0; _i < xBoxed.size(); ++_i)
            x[_i] = xBoxed.get(_i);
        reader.next();
        
        List<Integer> yBoxed = (List<Integer>) reader.next(new TypeRef<List<Integer>>(){}.getType());
        int[] y = new int[yBoxed.size()];
        for (int _i = 0; _i < yBoxed.size(); ++_i)
            y[_i] = yBoxed.get(_i);
        reader.close();

        TriangleEasy solver = new TriangleEasy();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.find(n, x, y));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }
}
