import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class Fragile2Solver {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        List<String> graphBoxed = (List<String>) reader.next(new TypeRef<List<String>>(){}.getType());
        String[] graph = new String[graphBoxed.size()];
        for (int _i = 0; _i < graphBoxed.size(); ++_i)
            graph[_i] = graphBoxed.get(_i);
        reader.close();

        Fragile2 solver = new Fragile2();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.countPairs(graph));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }
}
