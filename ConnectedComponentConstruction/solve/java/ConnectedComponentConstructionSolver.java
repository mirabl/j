import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class ConnectedComponentConstructionSolver {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        List<Integer> sBoxed = (List<Integer>) reader.next(new TypeRef<List<Integer>>(){}.getType());
        int[] s = new int[sBoxed.size()];
        for (int _i = 0; _i < sBoxed.size(); ++_i)
            s[_i] = sBoxed.get(_i);
        reader.close();

        ConnectedComponentConstruction solver = new ConnectedComponentConstruction();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        String[] result = solver.construct(s);
        List<String> resultBoxed = new ArrayList<String>();
        for (int _i = 0; _i < result.length; ++_i) {
            resultBoxed.add(result[_i]);
        }
        writer.write(resultBoxed);
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }
}
