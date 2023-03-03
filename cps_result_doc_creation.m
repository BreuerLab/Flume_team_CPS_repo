import mlreportgen.report.*
import mlreportgen.dom.*

doc=Document(file_name+"-report",'docx','report_template.dotx');
open(doc)
moveToNextHole(doc)
append(Doc,M)
moveToNextHole
