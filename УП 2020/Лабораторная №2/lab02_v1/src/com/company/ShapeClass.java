
import java.awt.*;
import java.awt.font.GlyphVector;
import java.awt.geom.AffineTransform;
import java.awt.geom.PathIterator;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;
import java.awt.image.BufferedImage;
import java.awt.image.RescaleOp;

public class ShapeClass implements Shape {

    static final int WIDTH = 840, HEIGHT = 410;

    @Override
    public Rectangle getBounds() {
        return null;
    }

    @Override
    public Rectangle2D getBounds2D() {
        return null;
    }

    @Override
    public boolean contains(double x, double y) {
        return false;
    }

    @Override
    public boolean contains(Point2D p) {
        return false;
    }

    @Override
    public boolean intersects(double x, double y, double w, double h) {
        return false;
    }

    @Override
    public boolean intersects(Rectangle2D r) {
        return false;
    }

    @Override
    public boolean contains(double x, double y, double w, double h) {
        return false;
    }

    @Override
    public boolean contains(Rectangle2D r) {
        return false;
    }

    @Override
    public PathIterator getPathIterator(AffineTransform at) {
        return null;
    }

    @Override
    public PathIterator getPathIterator(AffineTransform at, double flatness) {
        return null;
    }

    public BufferedImage draw(Graphics2D ig, Component c) {




        BufferedImage image = new BufferedImage(WIDTH / 2 - 10,400, BufferedImage.TYPE_INT_RGB);

        Graphics2D go = image.createGraphics();

        // Paint the entire background using a GradientPaint.
        // The background color varies diagonally from deep red to pale blue
        go.setPaint(new GradientPaint(0, 0, new Color(166, 166, 166),
                0, HEIGHT, new Color(255, 255, 255)));
        go.fillRect(0, 0, WIDTH, HEIGHT);          // fill the background

        // Use a different GradientPaint to draw a box.
        // This one alternates between deep opaque green and transparent green.
        // Note: the 4th arg to Color() constructor specifies color opacity
        go.setPaint(new GradientPaint(0, 0, new Color(0, 150, 0),
                20, 20, new Color(0, 150, 0, 0), true));
        go.setStroke(new BasicStroke(15));         // use wide lines

        go.setColor(Color.blue);
        go.drawLine(30, 380,380,380);
        go.drawLine(32, 375,173,77);
        go.drawLine(378, 375,173,77);


        // The glyphs of fonts can be used as Shape objects, which enables
        // us to use Java2D techniques with letters Just as we would with
        // any other shape.  Here we get some letter shapes to draw.
        Font font = new Font("Serif", Font.BOLD, 8);  // a basic font
        Font bigfont =                                // a scaled up version
                font.deriveFont(AffineTransform.getScaleInstance(30.0, 30.0));
        GlyphVector gv = bigfont.createGlyphVector(go.getFontRenderContext(),
                "!");
        Shape jshape = gv.getGlyphOutline(0);   // Shape of letter J


        // We're going to outline the letters with a 5-pixel wide line
        go.setStroke(new BasicStroke(5.0f));

        // We're going to fake shadows for the letters using the
        // following Paint and AffineTransform objects
        Paint shadowPaint = new Color(0, 0, 0, 100);     // Translucent black
        AffineTransform shadowTransform =
                AffineTransform.getShearInstance(-1.0, 0.0); // Shear to the right
        shadowTransform.scale(1.0, 0.5);                 // Scale height by 1/2

        // Move to the baseline of our first letter
        go.translate(145, 330);

        // Draw the shadow of the J shape
        go.setPaint(shadowPaint);
        go.translate(15,20);     // Compensate for the descender
        // transform the J into the shape of its shadow, and fill it
        go.fill(shadowTransform.createTransformedShape(jshape));
        go.translate(-15,-20);   // Undo the translation above

        // Now fill the J shape with a solid (and opaque) color
        go.setPaint(Color.blue);     // Fill with solid, opaque blue
        go.fill(jshape);             // Fill the shape
        go.setPaint(Color.black);    // Switch to solid black
        go.draw(jshape);             // And draw the outline of the J





        // We're going to fill the next letter using a TexturePaint, which
        // repeatedly tiles an image. The first step is to obtain the image.
        // We could load it from an image file, but here we create it
        // ourselves by drawing a into an off-screen image.  Note that we use
        // a GradientPaint to fill the off-screen image, so the fill pattern
        // combines features of both Paint classes.
        BufferedImage tile =                   // Create an image
                new BufferedImage(50, 50, BufferedImage.TYPE_INT_RGB);
        Graphics2D tg = tile.createGraphics(); // Get its Graphics for drawing
        tg.setColor(Color.pink);
        tg.fillRect(0, 0, 50, 50);     // Fill tile background with pink
        tg.setPaint(new GradientPaint(40, 0, Color.green,  // diagonal gradient
                0, 40, Color.gray)); // green to gray
        tg.fillOval(5, 5, 40, 40);     // Draw a circle with this gradient





        // For the last letter, use a custom Paint class to fill with a
        // complex mathematically defined pattern. The GenericPaint
        // class is defined in GenericPaint.java.
        go.setPaint(new GenericPaint() {
            public int computeRed(double x, double y) { return 128; }
            public int computeGreen(double x, double y) {
                return (int)((Math.sin(x/7) + Math.cos(y/5) + 2)/4 *255);
            }
            public int computeBlue(double x, double y) {
                return ((int)(x*y))%256;
            }
            public int computeAlpha(double x, double y) {
                return ((int)x%25*8+50) + ((int)y%25*8+50);
            }
        });
        // Fill letter A
        go.setPaint(Color.black);       // Revert to solid black



        ig.drawImage(image,0,0,null);

       return image;


    }
}
