package markup;
import java.util.List;

public class Paragraph extends AbstractElements {
	public void toHtml(StringBuilder str) {
		inH(str, "");
		
	}
	public void toTex(StringBuilder str) {
		inT(str, "");
		
	}
	public Paragraph(List <threeAble> list) {
		this.list = list;
	}
	public void toMarkdown(StringBuilder str) {
		inM(str, "");
	}
}
	