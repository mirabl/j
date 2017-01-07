import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class QuorumSolver {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        List<Integer> arrBoxed = (List<Integer>) reader.next(new TypeRef<List<Integer>>(){}.getType());
        int[] arr = new int[arrBoxed.size()];
        for (int _i = 0; _i < arrBoxed.size(); ++_i)
            arr[_i] = arrBoxed.get(_i);
        reader.next();
        
        int k = (Integer) reader.next(Integer.class);
        reader.close();

        Quorum solver = new Quorum();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.count(arr, k));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }
}
