import xml.etree.ElementTree as ET

data = {"name": "Ada", "age": "28", "city": "London"}

# Serialize to XML
root = ET.Element("data")

for key, value in data.items():

    child = ET.SubElement(root, key)
    child.text = str(value)

ET.ElementTree(root).write("data.xml", encoding="utf-8", xml_declaration=True)


# Deserialize from XML
tree = ET.parse("data.xml")
root = tree.getroot()
back = {child.tag: child.text for child in root}
