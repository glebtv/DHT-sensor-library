require 'digiusb'
p DigiUSB.sparks
spark = DigiUSB.sparks.last

loop do
  print msg = spark.gets
end
