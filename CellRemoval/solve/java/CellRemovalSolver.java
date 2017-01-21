import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class CellRemovalSolver {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        List<Integer> parentBoxed = (List<Integer>) reader.next(new TypeRef<List<Integer>>(){}.getType());
        int[] parent = new int[parentBoxed.size()];
        for (int _i = 0; _i < parentBoxed.size(); ++_i)
            parent[_i] = parentBoxed.get(_i);
        reader.next();
        
        int deletedCell = (Integer) reader.next(Integer.class);
        reader.close();

        CellRemoval solver = new CellRemoval();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.cellsLeft(parent, deletedCell));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }
}
