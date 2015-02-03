#
# Be sure to run `pod lib lint BleepMonitor.podspec' to ensure this is a
# valid spec and remove all comments before submitting the spec.
#
# Any lines starting with a # are optional, but encouraged
#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "BleepMonitor"
  s.version          = "1.6"
  s.summary          = "BLEep iOS SDK."
  s.description      = <<-DESC
                       BLEep BMS and SDKs
                       DESC
  s.homepage         = "https://github.com/PhuongNL/BleepMonitor"
  # s.screenshots     = "www.example.com/screenshots_1", "www.example.com/screenshots_2"
  s.license          = 'MIT'
  s.author           = { "Phuong Nguyen" => "phuongnl.hn@gmail.com" }
  s.source           = { :git => "https://github.com/PhuongNL/BleepMonitor.git", :tag => "1.6" }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source_files = 'Pod/Classes/**/*.{h,m}'
  s.resource_bundles = {
    'BleepMonitor' => ['Pod/Assets/*.png']
  }
  s.ios.vendored_library = 'Pod/Classes/bleepManager.a'
  s.public_header_files = 'Pod/Classes/**/*.h'
  s.frameworks = 'CoreLocation', 'UIKit', 'Foundation'
end
