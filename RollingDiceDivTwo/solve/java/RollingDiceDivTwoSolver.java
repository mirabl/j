import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class RollingDiceDivTwoSolver {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        List<String> rollsBoxed = (List<String>) reader.next(new TypeRef<List<String>>(){}.getType());
        String[] rolls = new String[rollsBoxed.size()];
        for (int _i = 0; _i < rollsBoxed.size(); ++_i)
            rolls[_i] = rollsBoxed.get(_i);
        reader.close();

        RollingDiceDivTwo solver = new RollingDiceDivTwo();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.minimumFaces(rolls));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }
}
