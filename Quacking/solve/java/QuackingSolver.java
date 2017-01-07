import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class QuackingSolver {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        String s = (String) reader.next(String.class);
        reader.close();

        Quacking solver = new Quacking();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.quack(s));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }
}
