import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class PathGameDiv2Solver {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        List<String> boardBoxed = (List<String>) reader.next(new TypeRef<List<String>>(){}.getType());
        String[] board = new String[boardBoxed.size()];
        for (int _i = 0; _i < boardBoxed.size(); ++_i)
            board[_i] = boardBoxed.get(_i);
        reader.close();

        PathGameDiv2 solver = new PathGameDiv2();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.calc(board));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }
}
