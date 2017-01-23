import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class DoubleWeightsSolver {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        List<String> weight1Boxed = (List<String>) reader.next(new TypeRef<List<String>>(){}.getType());
        String[] weight1 = new String[weight1Boxed.size()];
        for (int _i = 0; _i < weight1Boxed.size(); ++_i)
            weight1[_i] = weight1Boxed.get(_i);
        reader.next();
        
        List<String> weight2Boxed = (List<String>) reader.next(new TypeRef<List<String>>(){}.getType());
        String[] weight2 = new String[weight2Boxed.size()];
        for (int _i = 0; _i < weight2Boxed.size(); ++_i)
            weight2[_i] = weight2Boxed.get(_i);
        reader.close();

        DoubleWeights solver = new DoubleWeights();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.minimalCost(weight1, weight2));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }
}
