import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class ArcadeManaoSolver {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        List<String> levelBoxed = (List<String>) reader.next(new TypeRef<List<String>>(){}.getType());
        String[] level = new String[levelBoxed.size()];
        for (int _i = 0; _i < levelBoxed.size(); ++_i)
            level[_i] = levelBoxed.get(_i);
        reader.next();
        
        int coinRow = (Integer) reader.next(Integer.class);
        reader.next();
        
        int coinColumn = (Integer) reader.next(Integer.class);
        reader.close();

        ArcadeManao solver = new ArcadeManao();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.shortestLadder(level, coinRow, coinColumn));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }
}
