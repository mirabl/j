import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class ColorfulCoinsEasySolver {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        List<Integer> valuesBoxed = (List<Integer>) reader.next(new TypeRef<List<Integer>>(){}.getType());
        int[] values = new int[valuesBoxed.size()];
        for (int _i = 0; _i < valuesBoxed.size(); ++_i)
            values[_i] = valuesBoxed.get(_i);
        reader.close();

        ColorfulCoinsEasy solver = new ColorfulCoinsEasy();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.isPossible(values));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }
}
