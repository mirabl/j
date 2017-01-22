import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class BoxesDiv2Solver {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        List<Integer> candyCountsBoxed = (List<Integer>) reader.next(new TypeRef<List<Integer>>(){}.getType());
        int[] candyCounts = new int[candyCountsBoxed.size()];
        for (int _i = 0; _i < candyCountsBoxed.size(); ++_i)
            candyCounts[_i] = candyCountsBoxed.get(_i);
        reader.close();

        BoxesDiv2 solver = new BoxesDiv2();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.findSize(candyCounts));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }
}
