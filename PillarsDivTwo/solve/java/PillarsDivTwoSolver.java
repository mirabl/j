import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class PillarsDivTwoSolver {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        List<Integer> heightBoxed = (List<Integer>) reader.next(new TypeRef<List<Integer>>(){}.getType());
        int[] height = new int[heightBoxed.size()];
        for (int _i = 0; _i < heightBoxed.size(); ++_i)
            height[_i] = heightBoxed.get(_i);
        reader.next();
        
        int w = (Integer) reader.next(Integer.class);
        reader.close();

        PillarsDivTwo solver = new PillarsDivTwo();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.maximalLength(height, w));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }
}
