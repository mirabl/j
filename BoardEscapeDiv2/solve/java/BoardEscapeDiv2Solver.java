import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class BoardEscapeDiv2Solver {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        List<String> sBoxed = (List<String>) reader.next(new TypeRef<List<String>>(){}.getType());
        String[] s = new String[sBoxed.size()];
        for (int _i = 0; _i < sBoxed.size(); ++_i)
            s[_i] = sBoxed.get(_i);
        reader.next();
        
        int k = (Integer) reader.next(Integer.class);
        reader.close();

        BoardEscapeDiv2 solver = new BoardEscapeDiv2();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.findWinner(s, k));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }
}
